	1.	Topic Subscription:
	•	Each state subscribes to relevant ROS topics (e.g., april_tag_detection, obstacle_detection, digging_complete).
	2.	State Monitoring:
	•	Each state processes incoming messages and decides whether to transition.
	•	Example: In Exploration, if an AprilTag is detected, it transitions to Approach Tag.
	3.	Triggering Transitions:
	•	When a task completes (e.g., digging_complete), the state machine moves to the next state (e.g., Transport).
	4.	Feedback-Based Transitions:
	•	Continuous feedback (e.g., april_tag_distance) can trigger transitions, such as moving to Arrived State once close enough.
	5.	Custom Transitions:
	•	Events like arrived_at_tag or obstacle_avoided trigger custom state changes.

Example Transition Flow:

	1.	Idle → Exploration: Waits for command (start_exploration).
	2.	Exploration → AprilTag Detected: Detects AprilTag, transitions to Approach.
	3.	Approach → Arrived: Uses distance feedback to move to Arrived.
	4.	Arrived → Digging: Starts digging, waits for digging_complete.
	5.	Digging → Transport: Moves to transport state when digging finishes.