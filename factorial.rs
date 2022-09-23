// Generate factorial of upto `n`
// in rust using a simple for loop

use std::io;

fn main() {
    println!("Please input the number whose factorial you want.");
    let mut buffer = String::new();

    io::stdin()
        .read_line(&mut buffer)
        .expect("Could not read input");

    let num: i64 = buffer
        .trim()
        .parse()
        .expect("Provided input is not a valid number");

    let mut i = 1;
    let mut factorial = 1;
    while i < (num + 1) {
        factorial = factorial * i;
        i = i + 1;
    }
    println!("{num}! = {factorial}");
}