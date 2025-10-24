extends Area2D

@export var speed = 1500

# Called when the node enters the scene tree for the first time.
func _ready():
	top_level = true

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	position += (Vector2.RIGHT*speed).rotated(rotation) * delta


func _physics_process(delta):
	# await(get_tree().create_timer(0.01).timeout)
	# $sprite.frame = 1
	set_physics_process(false)


func _on_visible_on_screen_notifier_2d_screen_exited():
	queue_free()


func _on_body_entered(body):
	# player's hitbox cannot block their own bullets
	if(self.is_in_group("player_bullet") and not body.get_name() == "Player"):
		queue_free()
		
	# enemies can't shoot themselves or other enemies
	if (not self.is_in_group("player_bullet") and not body.is_in_group("enemy")):
		queue_free()


func _on_area_entered(area):
	_on_body_entered(area)
	
	# TODO player takes damage
	if not area.is_in_group("player_bullet"):
		pass
