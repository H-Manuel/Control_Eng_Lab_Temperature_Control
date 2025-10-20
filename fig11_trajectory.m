
function [t, w] = fig11_trajectory(yref, Ts, time)

    if nargin < 1 || isempty(yref), yref = 15; end
    if nargin < 2 || isempty(Ts),   Ts   = 0.1; end

    % Breakpoints (time in s, levels in °C relative to ambient)
    t_bp = [0 80 120 time];
    y_bp = [0 yref yref 0];

    % Time vector and piecewise-linear trajectory
    t = 0:Ts:t_bp(end);
    w = interp1(t_bp, y_bp, t, 'linear');

    % Plot when no outputs are requested
    if nargout == 0
        figure;
        plot(t, w, 'LineWidth', 1.5);
        xlabel('t / s');
        ylabel('Temperature / ^\circC');
        title('Figure 11: Temperature trajectory relative to ambient');
        grid on;
        xlim([0 t_bp(end)]);
        ylim([0 max(yref, eps)]);
    end
end
