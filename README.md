## Log Analyzer

This project is a command-line log analysis tool designed to help backend engineering teams identify the most frequent and impactful problems in application logs.

The system processes text-based log files, parses entries according to a configurable format, and produces aggregated results like error counts and the most common failure messages.

## Project Goals

* Read and analyze large log files efficiently
* Identify recurring problems (e.g. frequent error messages)
* Produce structured output that highlights where engineering effort should be focused
* Separate performance-critical logic (C++) from orchestration and UX (Java)

## Architecture Overview

* **C++ engine**: Handles log parsing, normalization, and aggregation
* **Java CLI**: Handles input validation, configuration, process orchestration, and user-facing output
* **Configuration-driven**: Log formats are explicitly defined (no auto-detection)

## Planned Features

* Configurable log format parsing
* Aggregation of log levels and error messages
* Ranking of most frequent problems
* Structured JSON output
* Human-readable CLI summary
