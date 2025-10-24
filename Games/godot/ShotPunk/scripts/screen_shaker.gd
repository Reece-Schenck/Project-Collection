extends Node

@onready var camera = get_parent()
var time = 0

# shakes the screen every bullet fired
func _shake(duration := 0.005, magnitude := 4):
	while time < duration:
		time += get_process_delta_time()
		time = min(time, duration)
		var offset = Vector2()
		offset.x = randf_range(-magnitude, magnitude)
		offset.y = randf_range(-magnitude, magnitude)
		camera.set_offset(offset)
		await(get_tree().create_timer(0.005).timeout)
	time = 0
	camera.set_offset(Vector2.ZERO)
