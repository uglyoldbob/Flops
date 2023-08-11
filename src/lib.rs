pub fn add(left: usize, right: usize) -> usize {
    left + right
}

extern "C" {
    pub fn sse_load(a: u32) -> f64;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}
