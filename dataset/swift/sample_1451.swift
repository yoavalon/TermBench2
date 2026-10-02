import Foundation

class DataProcessor {
    var data: [[String: Any]]

    init(data: [[String: Any]]) {
        self.data = data
    }

    func transform() -> [[String: Any]] {
        var transformedData: [[String: Any]] = []
        for item in data {
            if let quantity = item["quantity"] as? Int, quantity > 0,
               let price = item["price"] as? Double {
                let value = Double(quantity) * price
                transformedData.append(["product": item["name"] as! String, "value": value])
            }
        }
        return transformedData
    }
}

class AnalysisEngine {
    var processedData: [[String: Any]]

    init(processedData: [[String: Any]]) {
        self.processedData = processedData
    }

    func analyze() -> Double {
        var totalValue = 0.0
        for item in processedData {
            if let value = item["value"] as? Double {
                totalValue += value
            }
        }
        return totalValue
    }
}

class ReportingTool {
    var analysisResult: Double

    init(analysisResult: Double) {
        self.analysisResult = analysisResult
    }

    func report() -> String {
        return "Total Supply Chain Value: \(analysisResult)"
    }
}

func main() {
    let data: [[String: Any]] = [
        ["name": "Widget A", "quantity": 100, "price": 5.5],
        ["name": "Widget B", "quantity": 200, "price": 3.75],
        ["name": "Widget C", "quantity": 0, "price": 8.0]
    ]
    let processor = DataProcessor(data: data)
    let transformedData = processor.transform()
    let analyzer = AnalysisEngine(processedData: transformedData)
    let analysisResult = analyzer.analyze()
    let reporter = ReportingTool(analysisResult: analysisResult)
    let result = reporter.report()
    print(result)
}

main()