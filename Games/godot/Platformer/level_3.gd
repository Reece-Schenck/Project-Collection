extends Node2D

# loop back to first level
var simultaneous_scene = preload("res://level_1.tscn").instantiate()

func _on_finish_body_entered(body):
	#var current_scene_file = get_tree().current_scene.scene_file_path
	# may need to change
	#var next_level_number = current_scene_file.to_int() + 1
	var next_level_number = 1
	var next_level_path = "res://level_" + str(next_level_number) + ".tscn"
	get_tree().change_scene_to_file(next_level_path)
