use std::io;

fn read_num() -> u32 {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let num: u32 = match s.trim().parse() {
        Ok(num) => num,
        Err(_) => panic!("Not a number"),
    };
    num
}

fn read_row() -> (String, String, String) {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let mut iter = s.split_whitespace();

    let number = iter.next().unwrap().to_string();
    let source_lang = iter.next().unwrap().to_string();
    let target_lang = iter.next().unwrap().to_string();

    (number, source_lang, target_lang)
}

fn value_of(number: &String, source_lang: &String) -> u64 {
    let mut sum: u64 = 0;
    let base: u32 = source_lang.len() as u32;
    let num_len: u32 = number.len() as u32;
    for (i, c) in number.chars().enumerate() {
        let val_idx: u32 = source_lang.find(c).unwrap() as u32;
        let incr: u32 = val_idx * base.pow(num_len - (i as u32) - 1);
        sum += incr as u64;
    }
    sum
}

fn to_lang(mut number: u64, lang: &String) -> String {
    let mut output = String::new();
    let base: u64 = lang.len() as u64;

    while number > 0 {
        let v: u64 = number % base;
        let lang_val = lang.chars().nth(v as usize).unwrap();
        output.push(lang_val);
        number /= base;
    }

    output = output.chars().rev().collect::<String>();

    output
}

fn main() {
    let t = read_num();
    for i in 1..t + 1 {
        let (number, source_lang, target_lang) = read_row();
        let res = to_lang(value_of(&number, &source_lang), &target_lang);
        println!("Case #{}: {}", i, res);
    }
}
