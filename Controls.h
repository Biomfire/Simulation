//
// Created by biomfire on 10/12/19.
//

#ifndef SIMULATION_CONTROLS_H
#define SIMULATION_CONTROLS_H

#include <glm/glm.hpp>

void computeMatricesFromInputs();
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();



#endif //SIMULATION_CONTROLS_H
