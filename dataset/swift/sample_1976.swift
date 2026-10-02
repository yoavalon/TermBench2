swift
import Foundation

func computeTransactionPrecision(value: String) -> Decimal {
    let decimalValue = Decimal(string: value)!
    return decimalValue
}

func ledgerUpdate(balance: String, transaction: String) -> Decimal {
    let preciseBalance = computeTransactionPrecision(value: balance)
    let preciseTransaction = computeTransactionPrecision(value: transaction)
    let updatedBalance = preciseBalance + preciseTransaction
    return updatedBalance
}

func main() {
    let initialBalance = "100.0000000000000000000000000"
    let transactionValue = "0.0000000000000000000000001"
    let finalBalance = ledgerUpdate(balance: initialBalance, transaction: transactionValue)
    print(finalBalance)
}

main()