//
//  N개의 최소공배수.swift
//  Algorithm_programmers_swift
//
//  Created by jiniz.ll on 2022/01/25.
//

/*
 - 연습문제
 - [N개의 최소공배수](https://programmers.co.kr/learn/courses/30/lessons/12953)
 - Level 2
 */

import Foundation

func lcm(_ a: Int, _ b: Int) -> Int {
    
    return (a * b) / gcd(a, b)
}

func gcd(_ a: Int, _ b: Int) -> Int {
    
    var num = [a, b].max()!
    var divisor = [a, b].min()!
    
    while num % divisor != 0 {
        
        let remainder = num % divisor
        
        num = divisor
        divisor = remainder
    }
    return divisor
}

func solution(_ arr: [Int]) -> Int {
    
    return arr.reduce(arr[0]) { lcm($0, $1) }
}
