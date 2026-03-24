
pipeline {
    agent any
    
    options {
        timeout(time: 2, unit: 'MINUTES')
    }
    
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        
        stage('Build') {
            steps {
                sh 'g++ -o student_test main.cpp test.cpp -lgtest -lgtest_main -lpthread'
            }
        }
        
        stage('Test') {
            steps {
                // Run as non-root user for security
                sh 'sudo -u student-runner ./student_test --gtest_output="xml:report.xml"'
            }
        }
        
        stage('Post-Processing') {
            steps {
                sh 'python3 parse_results.py report.xml'
            }
        }
    }
    
    post {
        always {
            archiveArtifacts artifacts: 'report.xml', fingerprint: true
            junit 'report.xml'
        }
    }
}
