func generateState(temp: Double, press: Double, volume: Double) -> (Double, Double) {
    let energy = temp * volume
    let entropy = press / volume
    return (energy, entropy)
}

func mutateState(energy: Double, entropy: Double, factor: Double) -> (Double, Double) {
    let newEnergy = energy * factor
    let newEntropy = entropy * factor
    return (newEnergy, newEntropy)
}

func main() {
    let initialTemp = 300.0
    let initialPress = 1.0
    let initialVolume = 10.0
    let mutationFactor = 1.2
    let (energy, entropy) = generateState(temp: initialTemp, press: initialPress, volume: initialVolume)
    let (mutatedEnergy, mutatedEntropy) = mutateState(energy: energy, entropy: entropy, factor: mutationFactor)
    print("Initial Energy: \(energy) Initial Entropy: \(entropy)")
    print("Mutated Energy: \(mutatedEnergy) Mutated Entropy: \(mutatedEntropy)")
}

main()