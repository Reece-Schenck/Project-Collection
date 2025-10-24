extends CharacterBody2D

signal hit

@onready var screen_shaker = $Camera2D/screen_shaker

const SPEED = 300.0
const JUMP_VELOCITY = -500.0
const recoil_constant = 1000

# Get the gravity from the project settings to be synced with RigidBody nodes.
var gravity = ProjectSettings.get_setting("physics/2d/default_gravity")

var startX = 0
var startY = 0

func getStartLocationX():
	return position.x
	
func getStartLocationY():
	return position.y


func _physics_process(delta):
	if(startX == 0 and startY ==0):
		startX = getStartLocationX()
		startY = getStartLocationY()
		
	$AnimatedSprite2D.play()
	
	# Add the gravity.
	if not is_on_floor():
		velocity.y += gravity * delta

	# Handle jump.
	if (Input.is_action_just_pressed("jump") and is_on_floor() and $AnimatedSprite2D.animation != "roll"):
		velocity.y += JUMP_VELOCITY
		$AnimatedSprite2D.animation = "jump"


	# Get the input direction and handle the movement/deceleration.
	# As good practice, you should replace UI actions with custom gameplay actions.
	var direction = Input.get_axis("move_left", "move_right")
	if direction:
		velocity.x = direction * SPEED
		
		if(not Input.is_action_just_pressed("jump") and is_on_floor()):
			$AnimatedSprite2D.animation = "run"
			$AnimatedSprite2D.flip_v = false
			# See the note below about boolean assignment.
			$AnimatedSprite2D.flip_h = velocity.x < 0
			
			# player collision is off-centerd and this is the only way I could fix it
			if $AnimatedSprite2D.flip_h == true:
				$PlayerCollision.position.x = 14.5
			else:
				$PlayerCollision.position.x = -14.5
		
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)
	
	if(velocity.x == 0 && velocity.y == 0):
		$AnimatedSprite2D.animation = "idle"
		
	if(Input.is_action_pressed("crouch") && is_on_floor()):
		# velocity.x = direction * (SPEED*2)
		$AnimatedSprite2D.animation = "roll"
		$AnimatedSprite2D.flip_v = false
		$AnimatedSprite2D.flip_h = velocity.x < 0

	if(not Input.is_action_pressed("crouch") && Input.is_action_pressed("fire") && $shotgun.can_fire):
		# adds velocity opposite to where shotgun is pointed when fired
		var mouse_pos = get_global_mouse_position()
		var vect = mouse_pos - position
		var recoil = vect * -1
		#velocity.x = 0
		#velocity.y = 0
		
		velocity += recoil * 3
		
		# tweaked recoil to make it consistent reguardless of mouse placement
		if vect.x > 0 and vect.x < 250:
			velocity.x += recoil_constant * -1.75
		if vect.x > 250 and vect.x < 2000:
			velocity.x = recoil_constant * -2
			
		if vect.x < 0 and vect.x > -250:
			velocity.x += recoil_constant * 1.75
		if vect.x < -250 and vect.x > -2000:
			velocity.x = recoil_constant * 2
			
		if vect.y > 0 and vect.y < 100:
			velocity.y += recoil_constant * -0.35
		if vect.y > 100 and vect.y < 2000:
			velocity.y = recoil_constant * -0.55
			
		if vect.y < 0 and vect.y > -100:
			velocity.y += recoil_constant * 0.35
		if vect.y < -100 and vect.y > -2000:
			velocity.y = recoil_constant * 0.55
			
		
	move_and_slide()


func _add_point():
	$HUD.add_kill()


# TODO change to return to title screen
func respawn():
	position.x = startX
	position.y = startY


func _on_hazard_body_entered(body):
	# TODO add a grace period after getting hit so the player doesn't die instantly
	hit.emit()


func _on_hud_death():
	# TODO change to return to title screen
	$HUD.reset()
	respawn()


func _on_level_1_give_point():
	_add_point()
