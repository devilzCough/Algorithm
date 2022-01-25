//
//  행렬의 곱셈.swift
//  Algorithm_programmers_swift
//
//  Created by jiniz.ll on 2022/01/25.
//

/*
 - 연습문제
 - [행렬의 곱셈](https://programmers.co.kr/learn/courses/30/lessons/12949)
 - Level 2
 */

import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    
    var answer: [[Int]] = []
    
    for r in 0..<arr1.count {
        var row: [Int] = []
        for c in 0..<arr2[0].count {
            var sum = 0
            for i in 0..<arr2.count {
                sum += arr1[r][i] * arr2[i][c]
            }
            row.append(sum)
        }
        answer.append(row)
    }
    
    return answer
}
