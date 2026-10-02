func processFlightData() {
    var data = [
        ["id": 1, "altitude": 30000, "trajectory": "constant"],
        ["id": 2, "altitude": 35000, "trajectory": "ascending"],
        ["id": 3, "altitude": 32000, "trajectory": "descending"],
        ["id": 4, "altitude": 33000, "trajectory": "constant"],
        ["id": 5, "altitude": 31000, "trajectory": "ascending"]
    ]
    
    for entry in data {
        if entry["trajectory"] as! String == "ascending" {
            entry["altitude"] = (entry["altitude"] as! Int) + 1000
        } else if entry["trajectory"] as! String == "descending" {
            entry["altitude"] = (entry["altitude"] as! Int) - 500
        }
    }
    
    for entry in data {
        print("Flight \(entry["id"]!): Altitude \(entry["altitude"]!), Trajectory \(entry["trajectory"]!)")
    }
}

processFlightData()