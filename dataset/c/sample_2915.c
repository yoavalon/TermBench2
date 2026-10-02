#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_PROPOSALS 100

typedef struct {
    char* nodes[MAX_NODES];
    int threshold;
    char* ledger[MAX_PROPOSALS];
    int ledger_count;
    char* votes[MAX_PROPOSALS][MAX_NODES];
    int votes_count[MAX_PROPOSALS];
} ConsensusMechanism;

void add_vote(ConsensusMechanism* cm, char* node, char* proposal) {
    int found_node = 0;
    for (int i = 0; i < MAX_NODES && cm->nodes[i] != NULL; i++) {
        if (strcmp(cm->nodes[i], node) == 0) {
            found_node = 1;
            break;
        }
    }
    if (!found_node) return;

    int found_proposal = 0;
    for (int i = 0; i < MAX_PROPOSALS && cm->votes[i][0] != NULL; i++) {
        if (strcmp(cm->votes[i][0], proposal) == 0) {
            found_proposal = 1;
            int found_node_in_vote = 0;
            for (int j = 0; j < MAX_NODES && cm->votes[i][j] != NULL; j++) {
                if (strcmp(cm->votes[i][j], node) == 0) {
                    found_node_in_vote = 1;
                    break;
                }
            }
            if (!found_node_in_vote) {
                cm->votes[i][cm->votes_count[i]] = node;
                cm->votes_count[i]++;
                cm->check_consensus(cm, proposal);
            }
            break;
        }
    }
    if (!found_proposal) {
        cm->votes[cm->votes_count[cm->ledger_count]] = (char*[MAX_NODES]) {proposal};
        cm->votes_count[cm->votes_count[cm->ledger_count]] = 1;
        cm->check_consensus(cm, proposal);
    }
}

void check_consensus(ConsensusMechanism* cm, char* proposal) {
    for (int i = 0; i < MAX_PROPOSALS && cm->votes[i][0] != NULL; i++) {
        if (strcmp(cm->votes[i][0], proposal) == 0 && cm->votes_count[i] >= cm->threshold) {
            cm->ledger[cm->ledger_count] = proposal;
            cm->ledger_count++;
            cm->votes[i] = (char*[MAX_NODES]) {NULL};
            cm->votes_count[i] = 0;
            break;
        }
    }
}

void update_nodes(ConsensusMechanism* cm, char** new_nodes, int new_node_count) {
    for (int i = 0; i < new_node_count; i++) {
        cm->nodes[MAX_NODES - new_node_count + i] = new_nodes[i];
    }
}

char** generate_proposals(int count) {
    char** proposals = (char**) malloc(count * sizeof(char*));
    for (int i = 0; i < count; i++) {
        proposals[i] = (char*) malloc(20 * sizeof(char));
        sprintf(proposals[i], "Proposal %d", i);
    }
    return proposals;
}

void simulate_consensus() {
    ConsensusMechanism cm;
    cm.nodes[0] = "Node1";
    cm.nodes[1] = "Node2";
    cm.nodes[2] = "Node3";
    cm.nodes[3] = "Node4";
    cm.nodes[4] = "Node5";
    cm.threshold = 3;
    cm.ledger_count = 0;
    for (int i = 0; i < MAX_PROPOSALS; i++) {
        cm.votes[i] = (char*[MAX_NODES]) {NULL};
        cm.votes_count[i] = 0;
    }

    char** proposals = generate_proposals(10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            add_vote(&cm, cm.nodes[j], proposals[i]);
        }
    }

    while (1) {
        char* new_nodes[3];
        for (int i = 0; i < 3; i++) {
            new_nodes[i] = (char*) malloc(20 * sizeof(char));
            sprintf(new_nodes[i], "Node%d", cm.nodes[4] + i + 1);
        }
        update_nodes(&cm, new_nodes, 3);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 3; j++) {
                add_vote(&cm, new_nodes[j], proposals[i]);
            }
        }
    }
}

int main() {
    simulate_consensus();
    return 0;
}