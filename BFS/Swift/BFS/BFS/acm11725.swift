//
//  acm11725.swift
//  BFS
//
//  Created by 이승진 on 2021/01/02.
//

//7
//1 6
//6 3
//3 5
//4 1
//2 4
//4 7

//12
//1 2
//1 3
//2 4
//3 5
//3 6
//4 7
//4 8
//5 9
//5 10
//6 11
//6 12

import Foundation

var n: Int = 0
var graph: [[Int]] = []

// Queue 구현해야함
var queue: [Int] = []
var visited: [Int] = []

let root = 1

func  input() {
    n = Int(readLine()!)!
    graph = Array(repeating: [], count: n+1)
    visited = Array(repeating: 0, count: n+1)
    visited[root] = -1
    for _ in 1..<n {
        let node = readLine()!.components(separatedBy: " ").map { Int($0)! }
        graph[node[0]].append(node[1])
        graph[node[1]].append(node[0])
    }
}

func solve() {
    bfs()
}

func bfs() {
    
    for num in graph[root] {
        queue.append(num)
        visited[num] = root
    }
    
    while !queue.isEmpty {
        let parent = queue.popLast()!
        
        for num in graph[parent] {
            if visited[num] == 0 {
                visited[num] = parent
                queue.insert(num, at: 0)
            }
        }
    }
}

func output() {
    for num in 2...n {
        print(visited[num])
    }
}

func main() {
    
    input()
    solve()
    output()
}

// main()
