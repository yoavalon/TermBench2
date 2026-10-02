#include <iostream>
#include <vector>
#include <string>
#include <utility>

std::pair<std::string, std::string> process_state(const std::string& state, const std::string& data) {
    if (state == "start") {
        return {"connect", data};
    } else if (state == "connect") {
        if (data == "success") {
            return {"data_transfer", data};
        } else {
            return {"error", data};
        }
    } else if (state == "data_transfer") {
        if (data == "complete") {
            return {"disconnect", data};
        } else {
            return {"data_transfer", data};
        }
    } else if (state == "error") {
        return {"disconnect", data};
    } else if (state == "disconnect") {
        return {"end", data};
    } else {
        return {"end", data};
    }
}

void run_network_protocol(const std::vector<std::string>& data_sequence) {
    std::string current_state = "start";
    for (const auto& data : data_sequence) {
        std::tie(current_state, std::ignore) = process_state(current_state, data);
        if (current_state == "end") {
            break;
        }
    }
}

int main() {
    run_network_protocol({"success", "complete"});
    return 0;
}