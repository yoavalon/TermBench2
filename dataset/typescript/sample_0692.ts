function check_connection(state: string, attempts: number): string {
    if (attempts === 0) {
        return 'Disconnected';
    } else if (state === 'Connected') {
        return 'Connected';
    } else {
        return check_connection(attempts % 2 === 0 ? 'Connected' : 'Disconnected', attempts - 1);
    }
}

check_connection('Disconnected', 5);