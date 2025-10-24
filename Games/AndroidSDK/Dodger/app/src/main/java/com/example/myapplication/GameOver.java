package com.example.myapplication;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class GameOver extends AppCompatActivity {

    TextView tvPoints;
    TextView tvHighScores;
    SharedPreferences sharedPreferences;
    ImageView ivNewHighest;

    private static final String PREFS_NAME = "my_pref";
    private static final String SCORES_KEY = "high_scores";
    private static final int MAX_SCORES = 10;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.game_over);

        tvPoints = findViewById(R.id.tvPoints);
        tvHighScores = findViewById(R.id.tvHighScores);
        ivNewHighest = findViewById(R.id.ivNewHighest);

        int points = getIntent().getExtras().getInt("points");
        tvPoints.setText("" + points);


        // Had Chat GPT help me with the high scores, mainly with formatting
        sharedPreferences = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);
        List<Integer> highScores = getHighScores();

        // Add new score and update list
        addNewScore(highScores, points);

        // Save updated scores
        saveHighScores(highScores);

        // Display the top 10 scores
        tvHighScores.setText(formatScores(highScores));
    }

    // Load high scores from SharedPreferences
    private List<Integer> getHighScores() {
        String scoresString = sharedPreferences.getString(SCORES_KEY, "");
        List<Integer> scores = new ArrayList<>();

        if (!scoresString.isEmpty()) {
            for (String s : scoresString.split(",")) {
                scores.add(Integer.parseInt(s));
            }
        }
        return scores;
    }

    // Add a new score to the list and keep only the top 10
    private void addNewScore(List<Integer> scores, int newScore) {
        scores.add(newScore);
        scores.sort(Collections.reverseOrder()); // Sort descending

        if (scores.size() > MAX_SCORES) {
            scores.remove(scores.size() - 1); // Keep only top 10
        }
    }

    // Save updated high scores to SharedPreferences
    private void saveHighScores(List<Integer> scores) {
        StringBuilder sb = new StringBuilder();
        for (int score : scores) {
            sb.append(score).append(",");
        }
        sharedPreferences.edit().putString(SCORES_KEY, sb.toString()).apply();
    }

    // Format scores for display
    private String formatScores(List<Integer> scores) {
        StringBuilder formatted = new StringBuilder("Top Scores:\n");
        for (int i = 0; i < scores.size(); i++) {
            formatted.append(i + 1).append(". ").append(scores.get(i)).append("\n");
        }
        return formatted.toString();
    }

    public void restart(View view){
        GameView gameView = new GameView(this);
        setContentView(gameView);
    }

    public void exit(View view){
        finish();
    }
}
