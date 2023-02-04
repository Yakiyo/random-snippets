use std::io;

fn main() {
    println!("Please type a decimal number:");
    let mut res = String::new();
    io::stdin().read_line(&mut res).unwrap();
    let mut n: i64 = res
        .trim()
        .parse()
        .expect("Unable to parse provided value to number");
        
    println!("Please type the number system base to convert to");
    let mut bes = String::new();
    io::stdin().read_line(&mut bes).unwrap();
    let base: i64 = bes
        .trim()
        .parse()
        .expect("Unable to parse provided base to a number");
    if base > 10 {
        println!("Number systems of base more than 10 are not supported!");
        return
    }
    let mut r = Vec::new();
    while n != 0 {
        r.push(n % base);
        n = n / base;
    }
    r.reverse();
    let s: String = r.iter().map(|&id| id.to_string()).collect();
    println!("{s}");
}
