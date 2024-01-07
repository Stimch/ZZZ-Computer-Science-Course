#pragma once

#include "fsm_realization.h"

int Task(void) {
    const char* in_file_name = "in.txt";
    const char* out_file_name = "out.txt";
    StateMachine* sm = MakeStateMachine(in_file_name, out_file_name);
    int result = 0;
    while (true) {
        result = Step(sm);
        if (result) {
            break;
        }
    }
    DeleteStateMachine(sm);
}