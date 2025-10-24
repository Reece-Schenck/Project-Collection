extends Sprite2D

@onready var player = get_tree().current_scene.get_node('Player')
var can_fire = true
var bullet = preload("res://scenes/enemy_bullet.tscn")

func _ready():
	top_level = true
	
func _physics_process(delta):
	position.x = lerp(position.x, get_parent().position.x, 0.5)
	position.y = lerp(position.y-30, get_parent().position.y, 0.5)
	
	if player.global_position.x < global_position.x:
		flip_v = false  
		flip_h = false
		$Marker2D.scale.y = -1
	else:
		flip_v = true
		flip_h = true
		$Marker2D.scale.y = 1

	
	if (global_position.distance_to(player.global_position) < 600):
		look_at(player.global_position)
		if can_fire:
			var bullet_instance = bullet.instantiate()
			# slight bloom on the bullets fired
			bullet_instance.rotation = rotation + randf_range(-0.05, 0.05)
			bullet_instance.global_position = $Marker2D.global_position
			get_parent().add_child(bullet_instance)
			can_fire = false
			await(get_tree().create_timer(0.8).timeout)
			can_fire = true
