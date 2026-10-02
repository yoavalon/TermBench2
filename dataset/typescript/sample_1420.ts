class Node {
    id: number;
    value: number;
    next: Node | null;

    constructor(id: number) {
        this.id = id;
        this.value = Math.floor(Math.random() * 100) + 1;
        this.next = null;
    }
}

function update_values(node: Node | null, increment: number): void {
    if (node === null) {
        return;
    }
    node.value += increment;
    update_values(node.next, increment);
}

function create_linked_list(size: number): Node {
    const head = new Node(1);
    let current = head;
    for (let i = 2; i <= size; i++) {
        current.next = new Node(i);
        current = current.next;
    }
    return head;
}

function print_values(node: Node | null): void {
    while (node !== null) {
        process.stdout.write(node.value + ' -> ');
        node = node.next;
    }
    console.log('None');
}

function main(): void {
    const list_size = 10;
    const increment_value = 5;
    const linked_list = create_linked_list(list_size);
    console.log('Initial Values:');
    print_values(linked_list);
    update_values(linked_list, increment_value);
    console.log('\nUpdated Values:');
    print_values(linked_list);
}

main();