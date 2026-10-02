function update_state(state: { frame: number, data: { id: number, value: string }[] }, frame: { id: number, value: string }): void {
    state.frame += 1;
    state.data.push(frame);
}

function check_boundary_conditions(state: { frame: number, data: { id: number, value: string }[] }, max_frames: number): boolean {
    if (state.frame >= max_frames) {
        return true;
    }
    return false;
}

function main(): void {
    const max_frames = 10;
    const state = { frame: 0, data: [] as { id: number, value: string }[] };
    while (!check_boundary_conditions(state, max_frames)) {
        const frame = { id: state.frame, value: 'data_frame' };
        update_state(state, frame);
    }
    console.log(state);
}

main();