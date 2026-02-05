% Define your ThingSpeak channel parameters
channelID = ; % Change this to your actual channel ID (positive integer)
readAPIKey = ''; %Specify your API Key

% Specify the number of readings to fetch
numReadings = 1; % Fetch one reading at a time

% Create a timer object to fetch data periodically
t = timer('ExecutionMode', 'fixedRate', 'Period', 10, ... % Fetch data every 10 seconds
    'TimerFcn', {@fetchData, channelID, readAPIKey, numReadings});

% Start the timer
start(t);

% Wait for user to stop the timer manually
disp('Monitoring data in real-time. Press Ctrl+C to stop.');

% Callback function to fetch data
function fetchData(~, ~, channelID, readAPIKey, numReadings)
    % Read the data from ThingSpeak channel
    [data, timestamps] = thingSpeakRead(channelID, 'Fields', [1, 2, 3], 'NumPoints', numReadings, 'ReadKey', readAPIKey);

    % Extract ECG, SpO2, and Heart Rate data
    ecgData = data(:, 1);
    spo2Data = data(:, 2);
    heartRateData = data(:, 3);

    % Display the fetched data
    disp('ECG Data:');
    disp(ecgData);

    disp('SpO2 Data:');
    disp(spo2Data);

    disp('Heart Rate Data:');
    disp(heartRateData);

    % Check for abnormalities and display alerts
    for i = 1:numReadings
        if ecgData(i) < 60 || ecgData(i) > 100
            disp(['Alert: Abnormal ECG reading at timestamp ' datestr(timestamps(i))]);
        end
        if spo2Data(i) < 90 || spo2Data(i) > 100
            disp(['Alert: Abnormal SpO2 reading at timestamp ' datestr(timestamps(i))]);
        end
        if heartRateData(i) < 60 || heartRateData(i) > 100
            disp(['Alert: Abnormal Heart Rate reading at timestamp ' datestr(timestamps(i))]);
        end
    end
end