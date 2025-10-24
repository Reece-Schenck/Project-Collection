extends Sprite2D

var can_fire = true
var bullet = preload("res://scenes/bullet.tscn")

func _ready():
	top_level = true
	
func _physics_process(delta):
	position.x = lerp(position.x, get_parent().position.x, 0.5)
	position.y = lerp(position.y-10, get_parent().position.y, 0.5)
	var mouse_pos = get_global_mouse_position()
	look_at(mouse_pos)

	# flips gun sprite to always face the mouse
	if mouse_pos.x > global_position.x: 
		scale.y = 0.135
	else: 
		scale.y = -0.135
	
	if Input.is_action_pressed("fire") and can_fire:
		var bullet_instance = bullet.instantiate()
		# slight bloom on the bullets fired
		bullet_instance.rotation = rotation + randf_range(-0.05, 0.05)
		bullet_instance.global_position = $Marker2D.global_position
		get_parent().screen_shaker._shake(0.2, 2)
		get_parent().add_child(bullet_instance)
		can_fire = false
		await(get_tree().create_timer(0.55).timeout)
		can_fire = true
