use core::cmp::Ordering;
use std::io;
use std::io::Read;
use std::option::Option;
use std::collections::BinaryHeap;


fn read_num_players() -> u32 {
    let mut guess = String::new();
    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read number");
    let guess: u32 = match guess.trim().parse() {
        Ok(num) => num,
        Err(_) => panic!("Not a valid number"),
    };

    guess
}

fn next_num(words_iter: &mut std::str::SplitWhitespace) -> u64 {
	let word: String = match words_iter.next() {
		Some(w) => String::from(w),
		None => panic!("End of iterator"),
	};

	let num: u64 = match word.parse() {
		Ok(n) => n,
		Err(_) => panic!("Could not read num"),
	};

	num
}

fn read_players(n: u32) -> Vec<Player> {
    let mut buf = String::new();
    let stdin = io::stdin();
    let mut handle = stdin.lock();
    match handle.read_to_string(&mut buf) {
		Ok(_) => println!("Read string"),
		Err(_) => println!("Got Error"),
	};
	
	let mut vec = Vec::new();
	let mut iter = buf.split_whitespace();
	for i in 0..n {
		let name: String = match iter.next() {
			Some(s) => String::from(s),
			None => panic!("End of iterator"),
		};

		let skill_1 = next_num(&mut iter);
		let skill_2 = next_num(&mut iter);
		let skill_3 = next_num(&mut iter);
		
		vec.push(Player {
            name: name,
			skills: [skill_1, skill_2, skill_3],
		});
	}

    vec
}

struct Player {
    name: String,
    skills: [u64; 3],
}

struct SkillComp {
    player: &Player,
    skill: usize,
}

impl Ord for SkillComp {
    fn cmp(&self, other: &Self) -> Ordering {
        self.player.skills[self.skill].cmp(&other.player.skills[self.skill])
    }
}

impl PartialOrd for SkillComp {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for SkillComp {
    fn eq(&self, other: &Self) -> bool {
        self.player.skills[self.skill] == other.player.skills[self.skill]
    }
}

impl Eq for SkillComp {}

fn main() {
    let num_players = read_num_players();
	let players = read_players(num_players);

	//let mut heap1 = BinaryHeap::new();
	// let mut heap2 = BinaryHeap::new();
	// let mut heap2 = BinaryHeap::new();
	for player in players {
		//heap1.push(SkillComp { player: player, skill: 1 });
	}
			

    println!("{}", players.len());
}
