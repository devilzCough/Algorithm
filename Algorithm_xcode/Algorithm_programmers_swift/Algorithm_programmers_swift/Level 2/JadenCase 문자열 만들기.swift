//
//  JadenCase 문자열 만들기.swift
//  Algorithm_programmers_swift
//
//  Created by jiniz.ll on 2022/01/25.
//

/*
 - 연습문제
 - [JadenCase 문자열 만들기](https://programmers.co.kr/learn/courses/30/lessons/12951)
 - Level 2
 */

import Foundation

func solution(_ s: String) -> String {
    
    var words = s.lowercased().components(separatedBy: " ")
    for (i, word) in words.enumerated() {
        if word.isEmpty { continue }
        var arr = Array(word).map { String($0) }
        arr[0] = arr[0].uppercased()
        words[i] = arr.joined(separator: "")
    }
    
    return words.joined(separator: " ")
}
