//
//  피보나치 수.swift
//  Algorithm_programmers_swift
//
//  Created by jiniz.ll on 2022/01/25.
//

/*
 - 연습문제
 - [피보나치 수](https://programmers.co.kr/learn/courses/30/lessons/12945)
 - Level 2
 */

import Foundation

func solution(_ n: Int) -> Int {
    
    var fibonacci = [0, 1]
    for i in 2...n {
        let next = (fibonacci[i-1] + fibonacci[i-2]) % 1234567
        fibonacci.append(next)
    }
    
    return fibonacci[n]
}
