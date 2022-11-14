use std::collections::HashMap;

fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut observed: HashMap<i32, i32> = HashMap::new();

    let mut pos: i32 = 0;
    for num in nums {
        let complement = target-num;
        if observed.contains_key(&complement) {
            let search_result: i32 = *observed.get(&complement).unwrap();
            return vec![search_result, pos];
        } else {
            observed.entry(num).or_insert(pos);
        }
        pos += 1;
    }
    return vec![];
}

fn main() {
    println!("{:?}", two_sum(vec![1, 2, 3, 4], 7));
}
