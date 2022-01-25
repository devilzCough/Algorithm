//
//  최솟값 만들기.swift
//  Algorithm_programmers_swift
//
//  Created by jiniz.ll on 2022/01/25.
//

/*
 - 연습문제
 - [최솟값 만들기](https://programmers.co.kr/learn/courses/30/lessons/12941)
 - Level 2
 */

import Foundation

func solution(_ A:[Int], _ B:[Int]) -> Int
{
    var answer = 0
    
    let a = A.sorted()
    let b = B.sorted(by: >)
    for i in 0..<a.count {
        answer += a[i] * b[i]
    }

    return answer
}
