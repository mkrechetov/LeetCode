use std::collections::HashSet;

fn find_repeated_dna_sequences(s: String) -> Vec<String> {
    let mut observed = HashSet::new();
    let mut result = HashSet::new();
    let n = s.chars().count();
    if n < 10 {
        return vec![];
    } else {
        for i in 0..(n-9) {
            if observed.contains(&s[i..i+10]) {
                result.insert(String::from(&s[i..i+10]));
            } else {
                observed.insert(String::from(&s[i..i+10]));
            }
        }
        return result.into_iter().collect();
    }
}


fn main() {
    println!("{:?}", find_repeated_dna_sequences(String::from("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")));
    println!("{:?}", find_repeated_dna_sequences(String::from("AAAAAAAAAAAAA")));
    println!("{:?}", find_repeated_dna_sequences(String::from("AAAAAAAAAAA")));
    println!("{:?}", find_repeated_dna_sequences(String::from("AAAAAAAAAA")));
}
