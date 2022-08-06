use std::time::SystemTime;

// return position of the element if found
fn binary_search(vec: &[u32], item: u32) -> Option<usize> {
    let mut low: u32 = 0;
    let mut len: u32 = vec.len() as u32 - 1;
    while low <= len {
        let i = ((low + len) / 2) as usize;
        if vec[i] == item {
            return Some(i);
        } else if vec[i] > item {
            len = i as u32 - 1;
        } else if vec[i] < item {
            low = i as u32 + 1;
        }
    }
    None
}

fn main() {
    let max_item_value: u32 = 1_000_000_000;
    let vec: Vec<u32> = (0..max_item_value).collect();
    let item: u32 = 5;

    let sys_time = SystemTime::now();

    binary_search(&vec, item);

    let new_sys_time = SystemTime::now();

    let difference = new_sys_time
        .duration_since(sys_time)
        .expect("Clock may have gone backwards");
    println!("{difference:?}");
}
