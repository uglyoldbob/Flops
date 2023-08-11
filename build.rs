#![allow(unused_imports, dead_code, unused_variables)]

#[cfg(feature = "bindgen")]
extern crate bindgen;
#[macro_use]
extern crate cfg_if;
#[cfg(feature = "bundled")]
extern crate cmake;
#[cfg(feature = "pkg-config")]
extern crate pkg_config;

use std::path::{Path, PathBuf};
use std::process::Command;
use std::{env, fs, io};

fn compile(sdl2_build_path: &Path, target_os: &str) -> PathBuf {
    let mut cfg = cmake::Config::new(sdl2_build_path);
    if let Ok(profile) = env::var("CPULOAD_BUILD_PROFILE") {
        cfg.profile(&profile);
    } else {
        cfg.profile("release");
    }

    // Allow specifying custom toolchain specifically for SDL2.
    if let Ok(toolchain) = env::var("CPULOAD_TOOLCHAIN") {
        cfg.define("CMAKE_TOOLCHAIN_FILE", &toolchain);
    } else {
        // Override __FLTUSED__ to keep the _fltused symbol from getting defined in the static build.
        // This conflicts and fails to link properly when building statically on Windows, likely due to
        // COMDAT conflicts/breakage happening somewhere.
        #[cfg(feature = "static-link")]
        cfg.cflag("-D__FLTUSED__");

        #[cfg(target_os = "linux")]
        {
            // Add common flag for affected version and above
            use version_compare::{compare_to, Cmp};
            if let Ok(version) = std::process::Command::new("cc")
                .arg("-dumpversion")
                .output()
            {
                let affected =
                    compare_to(std::str::from_utf8(&version.stdout).unwrap(), "10", Cmp::Ge)
                        .unwrap_or(true);
                if affected {
                    cfg.cflag("-fcommon");
                }
            }
        }
    }
    cfg.build()
}

fn main() {
    let target = env::var("TARGET").expect("Cargo build scripts always have TARGET");
    let host = env::var("HOST").expect("Cargo build scripts always have HOST");
    let target_os = get_os_from_triple(target.as_str()).unwrap();

    let mut source_path = PathBuf::from(env::var("CARGO_MANIFEST_DIR").unwrap());

    source_path.push("version3");
    let compiled_path: PathBuf = compile(source_path.as_path(), target_os);

    println!(
        "cargo:rustc-link-search={}",
        compiled_path.join("lib64").display()
    );
    println!(
        "cargo:rustc-link-search={}",
        compiled_path.join("lib").display()
    );

    let includes = source_path
        .join("include")
        .to_str()
        .unwrap()
        .to_string();
}

fn get_os_from_triple(triple: &str) -> Option<&str> {
    triple.splitn(3, "-").nth(2)
}