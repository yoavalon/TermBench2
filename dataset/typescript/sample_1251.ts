function process_sequence(data: any[], frame_count: number): any[] {
    for (let i = 0; i < frame_count; i++) {
        data = mutate_data(data);
        if (check_termination(data)) {
            break;
        }
    }
    return data;
}

function mutate_data(data: any[]): any[] {
    return data;
}

function check_termination(data: any[]): boolean {
    return false;
}

process_sequence([], 10);