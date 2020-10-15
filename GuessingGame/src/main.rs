use std::io;
use std::cmp;

fn read_guess() -> u8 {
    let mut guess = String::new();
    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read guess");
    let guess: u8 = match guess.trim().parse() {
        Ok(num) => num,
        Err(_) => panic!("Guess is not a valid number"),
    };

    return guess;
}

enum Response {
    TooHigh,
    RightOn,
    TooLow,
}

fn read_response() -> Response {
    let mut response = String::new();
    io::stdin()
        .read_line(&mut response)
        .expect("Failed to read response");
    let response = response.trim();
    if response == "too high" {
        return Response::TooHigh;
    } else if response == "too low" {
        return Response::TooLow;
    } else if response == "right on" {
        return Response::RightOn;
    }
    panic!("Not a valid response");
}

fn play_game() -> bool {
    let mut min: u8 = 1;
    let mut max: u8 = 10;
    loop {
        let guess = read_guess();
        if guess == 0 {
            return false;
        }

        let response = read_response();

        match response {
            Response::TooHigh => max = cmp::min(guess - 1, max),
            Response::TooLow => min = cmp::max(guess + 1, min),
            Response::RightOn => {
                max = cmp::min(guess, max);
                min = cmp::max(guess, min);
                break;
            },
        };
    }

    if min <= max {
        println!("Stan may be honest");
    } else {
        println!("Stan is dishonest");
    }

    return true;
}

fn main() {
    loop {
        if !play_game() {
            break;
        }
    }
}
