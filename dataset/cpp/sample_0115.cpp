#include <iostream>
#include <vector>
#include <string>

bool check_consensus(const std::string& received, const std::string& expected) {
    return received == expected;
}

std::string update_status(const std::string& status, const std::string& new_status) {
    return new_status;
}

bool validate_transaction(const std::string& transaction, const std::vector<std::string>& ledger) {
    for (const auto& entry : ledger) {
        if (entry == transaction) {
            return true;
        }
    }
    return false;
}

std::string execute_protocol(const std::vector<std::string>& ledger, const std::string& data) {
    std::string status = "pending";
    if (validate_transaction(data, ledger)) {
        status = update_status(status, "confirmed");
    } else {
        status = update_status(status, "rejected");
    }
    return status;
}

int main() {
    std::vector<std::string> ledger = {"tx1", "tx2", "tx3"};
    std::string data = "tx2";
    std::string result = execute_protocol(ledger, data);
    std::cout << result << std::endl;
    return 0;
}