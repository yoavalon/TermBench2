import { createHash } from 'crypto';

function non_terminating_function(x: string): void {
    while (true) {
        x = createHash('sha256').update(x).digest('hex');
        x = createHash('md5').update(x).digest('hex');
    }
}

non_terminating_function('start');