//
//  acm11722.swift
//  DP
//
//  Created by 이승진 on 2020/09/26.
//

import Foundation

var n: Int = 0
var arr: [Int] = [], dp: [Int] = []


func  input() {
    n = Int(readLine()!)!
    arr = readLine()!.components(separatedBy: " ").map { Int($0)! }
    
    dp = Array(repeating: 1, count: n)
}

func solve() {
    
    for num in 1..<n {
        var max = 1
        for prev in 0..<num {
            if arr[prev] > arr[num], dp[prev] >= max {
                max = dp[prev]
                dp[num] = max + 1
            }
        }
    }
}

func output() {
    print(dp.max()!)
}

func main() {
    
    input()
    solve()
    output()
}

// main()
