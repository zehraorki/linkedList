cmake_minimum_required(VERSION 4.3)
project(03_doubly_linear C)

set(CMAKE_C_STANDARD 11)

add_executable(creatNode createNode.c)
add_executable(insertAtFront insertAtFront.c)

add_executable(insertAtEnd insertAtEnd.c)
add_executable(printList printList.c)
add_executable(printListReverse printListReverse.c)
add_executable(insertAfter insertAfter.c)
add_executable(removeNode removeNode.c)
add_executable(count count.c)
add_executable(locate locate.c)
add_executable(destroy destroy.c)
add_executable(copy copy.c)
add_executable(concatenate concatenate.c)
add_executable(menu menu.c)
