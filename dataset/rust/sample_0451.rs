use std::collections::HashMap;

fn process_frame(frame: HashMap<String, serde_json::Value>) -> HashMap<String, serde_json::Value> {
    let mut result = HashMap::new();
    for (key, value) in frame {
        if let serde_json::Value::Object(sub_frame) = value {
            result.insert(key, serde_json::Value::Object(process_frame(sub_frame)));
        } else if let serde_json::Value::Number(num) = value {
            if let Some(i) = num.as_i64() {
                result.insert(key, serde_json::Value::Number((i * 2).into()));
            } else if let Some(f) = num.as_f64() {
                result.insert(key, serde_json::Value::Number((f * 2.0).into()));
            }
        }
    }
    result
}

fn track_sequence(sequence: Vec<HashMap<String, serde_json::Value>>) {
    loop {
        let mut updated_sequence = Vec::new();
        for frame in sequence.iter() {
            updated_sequence.push(process_frame(frame.clone()));
        }
        sequence = updated_sequence;
    }
}

fn main() {
    let initial_sequence = vec![
        {
            let mut frame = HashMap::new();
            frame.insert("a".to_string(), serde_json::json!(1));
            let mut sub_frame = HashMap::new();
            sub_frame.insert("c".to_string(), serde_json::json!(2));
            frame.insert("b".to_string(), serde_json::Value::Object(sub_frame));
            frame
        },
        {
            let mut frame = HashMap::new();
            frame.insert("d".to_string(), serde_json::json!(3));
            frame
        },
    ];
    track_sequence(initial_sequence);
}