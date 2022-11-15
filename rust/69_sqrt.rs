fn my_sqrt(x: i32) -> i32 {
    match x {
        0 | 1 => {
            return x;
        }
        _ => {
            for i in 1..46339 {
                if (i+1)*(i+1) > x {
                    return i;
                }
            }
            if x < 2147395600 {
                return 46339;
            } else {
                return 46340;
            }
        }
    }
}

fn main() {
    assert_eq!(my_sqrt(2147395600), 46340);
    assert_eq!(my_sqrt(2147395599), 46339);
    assert_eq!(my_sqrt(0), 0);
    assert_eq!(my_sqrt(1), 1);
    assert_eq!(my_sqrt(4), 2);
}
