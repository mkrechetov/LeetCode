fn is_palindrome(x: i32) -> bool {
    let x_forward = x.to_string();
    let x_revert = x_forward.chars().rev().collect::<String>();
    return x_forward == x_revert;
}

fn is_palindrome_2(x: i32) -> bool {
    let x_str = x.to_string();
    if x_str.len() <= 1 {
        return true;
    } else {
        let mid = x_str.len()/2;
        let (a, b) = x_str.split_at(mid);
        if x_str.len() % 2 == 1 {
            let b_revert = b[1..].chars().rev().collect::<String>();
            return b_revert == a;
        } else {
            let b_revert = b.chars().rev().collect::<String>();
            return b_revert == a;
        }
    }
}

fn main() {
    assert_eq!(is_palindrome(121), true);
    assert_eq!(is_palindrome(1221), true);
    assert_eq!(is_palindrome(22222), true);
    assert_eq!(is_palindrome(0), true);
    assert_eq!(is_palindrome(1), true);
    assert_eq!(is_palindrome(10), false);
    assert_eq!(is_palindrome(1010), false);
}
