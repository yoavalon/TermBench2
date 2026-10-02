function main() {

function check_connection(state) {
    if (state === 'open') {
        console.log('Connection is open.');
        check_connection('open');
    } else if (state === 'closed') {
        console.log('Connection is closed.');
        check_connection('open');
    } else {
        console.log('Unknown state.');
        check_connection('open');
    }
}
check_connection('open');
}
main();