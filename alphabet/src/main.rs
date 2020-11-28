use std::cmp::min;
use std::io;

const LAST_LETTER: char = 'z';

fn letters_to_add(s: &str) -> u32 {
    return letters_to_add_helper(&s, 'a', 0);
}

fn letters_to_add_helper(s: &str, c: char, i: usize) -> u32 {
    if i == s.len() {
        return (chsub(LAST_LETTER, c) + 1) as u32;
    }

    let c_i = s.chars().nth(i).unwrap();

    if c_i == next_char(LAST_LETTER) {
        return 0;
    }

    if c_i < c {
        return letters_to_add_helper(&s, c, i + 1);
    }

    if c_i == c {
        return letters_to_add_helper(&s, next_char(c), i + 1);
    }

    let diff = chsub(c_i, c) as u32;
    return min(diff + letters_to_add_helper(&s, next_char(c_i), i + 1),
                      letters_to_add_helper(&s, c, i + 1));
}

fn chsub(a: char, b: char) -> i32 {
    a as i32 - b as i32
}

fn next_char(c: char) -> char {
    ((c as u8) + 1) as char
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let s = s.trim();
    println!("{}", letters_to_add(&s));
}
