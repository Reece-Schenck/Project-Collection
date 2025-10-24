extends Node2D

signal give_point


func _on_finish_body_entered(body):
	#var current_scene_file = get_tree().current_scene.scene_file_path
	#var next_level_number = current_scene_file.to_int() + 1
	var next_level_number = 2
	var next_level_path = "res://scenes/level_" + str(next_level_number) + ".tscn"
	get_tree().change_scene_to_file(next_level_path)
