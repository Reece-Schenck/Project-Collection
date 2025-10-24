extends CanvasLayer

var kills = 0
var health = 3
signal death

func reset():
	kills = 0
	health = 3
	$kill_counter.text = "Kills: " + str(kills)
	$health_tracker.text = "Health " + str(health)

func add_kill():
	kills += 1
	$kill_counter.text = "Kills: " + str(kills)
	
func remove_health():
	health -= 1
	$health_tracker.text = "Health " + str(health)
	
	if health <= 0:
		death.emit()

# Called when the node enters the scene tree for the first time.
func _ready():
	pass


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


func _on_player_hit():
	remove_health()
