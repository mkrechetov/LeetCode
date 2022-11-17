use std::collections::HashSet;
use std::collections::HashMap;

fn find_repeated_dna_sequences_1(s: String) -> Vec<String> {
    let n = s.chars().count();
    if n < 10 {
        return vec![];
    } else {
        let mut observed = HashSet::new();
        let mut result = HashSet::new();

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

fn find_repeated_dna_sequences_2(s: String) -> Vec<String> {
    let n = s.chars().count();
    if n < 10 {
        return vec![];
    } else {
        let mut observed = HashSet::new();
        let mut result = HashSet::new();

        let mut current = String::from(&s[..10]);
        observed.insert(String::from(&current));

        for i in 10..n {
            current.remove(0);
            current.push_str(&s[i..i+1]);
            if observed.contains(&current) {
                result.insert(String::from(&current));
            } else {
                observed.insert(String::from(&current));
            }
        }
        return result.into_iter().collect();
    }
}

fn find_repeated_dna_sequences(s: String) -> Vec<String> {
    let n = s.chars().count();
    if n < 10 {
        return vec![];
    } else {
        let mut observed = HashMap::new();
        for i in 0..(n-9) {
            observed.entry(&s[i..i+10]).and_modify(|occ| *occ += 1).or_insert(1);
        }

        let mut result = vec![];
        for (key, val) in observed.iter() {
            if *val >= 2 {
                result.push(String::from(*key));
            }
        }

        return result;
    }
}

fn main() {
    println!("{:?}", find_repeated_dna_sequences(String::from("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")));
    println!("{:?}", find_repeated_dna_sequences(String::from("AAAAAAAAAAAAA")));
    println!("{:?}", find_repeated_dna_sequences(String::from("AAAAAAAAAAA")));
    println!("{:?}", find_repeated_dna_sequences(String::from("AAAAAAAAAA")));
}
