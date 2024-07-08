
# Philosophers

## Overview

The Philosophers project introduces you to threading and mutexes through a simulation involving philosophers dining at a round table. You'll learn essential concepts of concurrency and synchronization in multi-threaded environments.

## Features

-   Simulate philosophers dining and thinking with threads.
-   Ensure no deadlock or starvation occurs using mutexes to manage forks.
-   Log and display each philosopher's actions: eating, thinking, sleeping, and dying.
-   Handle optional constraints like the maximum number of times a philosopher must eat before the simulation ends.
-   Implement error-free handling and graceful termination of the simulation.

## Installation

1.  **Clone the repository**:`git clone https://github.com/mbrettsc/philosophers.git && cd philosophers` 
    
2.  **Build the project**:   `make` 
    

## Usage

Run the simulation with the mandatory parameters:
`./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]` 

## Dependencies

-   `gcc` (or any compatible C compiler)
-   `make` build automation tool

## Mandatory Part

Program name: `philo`

-   Utilizes threads and mutexes to simulate philosophers dining.
-   Ensures thread safety and proper synchronization.

## Bonus Part

Program name: `philo_bonus`

-   Uses processes and semaphores for synchronization.
-   Implements the simulation with the forks managed by semaphores in the center.
