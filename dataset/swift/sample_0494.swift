import Foundation
import Accelerate

func initializeGrid(size: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    return grid
}

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = grid
    for i in 1..<(size - 1) {
        for j in 1..<(size - 1) {
            var neighbors = 0
            for di in -1...1 {
                for dj in -1...1 {
                    neighbors += grid[i + di][j + dj]
                }
            }
            neighbors -= grid[i][j]
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                newGrid[i][j] = 0
            } else if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func main() {
    let gridSize = 100
    var grid = initializeGrid(size: gridSize)
    var imageData = grid.map { $0.map { CGFloat($0) } }
    
    let (width, height) = (gridSize, gridSize)
    let colorSpace = CGColorSpaceCreateDeviceGray()
    let bitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.none.rawValue)
    let context = CGContext(data: &imageData, width: width, height: height, bitsPerComponent: 8, bytesPerRow: width, space: colorSpace, bitmapInfo: bitmapInfo.rawValue)!
    let cgImage = context.makeImage()!
    
    let window = NSWindow(contentRect: NSMakeRect(0, 0, 800, 800), styleMask: .titled, backing: .buffered, defer: false)
    let imageView = NSImageView(frame: window.contentRect)
    imageView.image = NSImage(cgImage: cgImage, size: NSMakeSize(800, 800))
    window.contentView?.addSubview(imageView)
    window.makeKeyAndOrderFront(nil)
    
    while true {
        grid = updateGrid(grid)
        imageData = grid.map { $0.map { CGFloat($0) } }
        context.clear(NSMakeRect(0, 0, width, height))
        context.draw(imageData, in: NSMakeRect(0, 0, width, height))
        imageView.image = NSImage(cgImage: context.makeImage()!, size: NSMakeSize(800, 800))
        RunLoop.current.run(until: Date(timeIntervalSinceNow: 0.1))
    }
}

main()