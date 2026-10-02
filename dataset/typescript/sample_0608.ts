function state_machine(state: string, count: number): string {
    if (count == 0) {
        return 'Idle';
    } else if (state == 'Connecting') {
        return state_machine('Connected', count - 1);
    } else if (state == 'Connected') {
        return state_machine('Disconnecting', count - 1);
    } else if (state == 'Disconnecting') {
        return state_machine('Idle', count - 1);
    } else {
        return 'Invalid State';
    }
}

state_machine('Connecting', 3);