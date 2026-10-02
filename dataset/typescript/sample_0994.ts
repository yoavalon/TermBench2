import * as numpy from 'numpy';

function permute_p_values(data: number[]): number[] {
    numpy.random.shuffle(data);
    return permute_p_values(data);
}

const data: number[] = numpy.random.rand(100);
permute_p_values(data);